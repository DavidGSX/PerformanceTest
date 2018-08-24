package test;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Set;

public class NioServer {

    private Selector selector;
    private ServerSocketChannel serverSocketChannel;
    private int port;

    public NioServer(int port) throws IOException {
        serverSocketChannel = ServerSocketChannel.open();
        serverSocketChannel.configureBlocking(false);
        selector = Selector.open();
        this.port = port;   
    }

    private void selectLoop() throws IOException {
        while(true) {
            
            selector.select();
            
            Set<SelectionKey> selectionKeys = selector.selectedKeys();
            Iterator<SelectionKey> iterator = selectionKeys.iterator();
            while(iterator.hasNext()) {
                SelectionKey selectionKey = iterator.next();
                
                if (selectionKey.isAcceptable()) {
                   
                    acceptClient(selectionKey);
                }else if(selectionKey.isReadable()) {
                    
                    readDate(selectionKey);
                }
            }
            selectionKeys.clear();
        }
    }


    private void acceptClient(SelectionKey selectionKey) throws IOException {
       
        SocketChannel socketChannel = serverSocketChannel.accept();

        if (socketChannel != null) {
        	System.out.println("接收一个连接，对端IP为："+socketChannel.socket().getInetAddress()+"端口为："+socketChannel.socket().getPort());
	}
        
        socketChannel.configureBlocking(false);
        socketChannel.register(selector, SelectionKey.OP_READ);
    }

    private void readDate(SelectionKey selectionKey) throws IOException {

       
        ByteBuffer oldBuffer = (ByteBuffer)selectionKey.attachment();

        SocketChannel socketChannel = (SocketChannel) selectionKey.channel();
        ByteBuffer newBuffer = ByteBuffer.allocate(640);

        try {
			while(socketChannel.read(newBuffer)<=0) {
				System.out.println("关闭一个连接，对端IP为："+socketChannel.socket().getInetAddress()+"端口为："+socketChannel.socket().getPort());
				socketChannel.close();
			    return;
			}
		} catch (IOException e) {
			System.out.println("关闭连接，对端IP为："+socketChannel.socket().getInetAddress()+"端口为："+socketChannel.socket().getPort());
			socketChannel.close();
		}

        newBuffer.flip();
        String line = readLine(newBuffer);
        if (line != null) {

            //System.out.println("Receive[" + line + "]");
            String sendData = readLine(mergeBuffer(oldBuffer, newBuffer));
            //System.out.println("Send   [" + line + "]");
 	    //System.out.println("Send Bytes =" + Arrays.toString(sendData.getBytes()));          
            ByteBuffer sendBuffer = ByteBuffer.wrap(sendData.getBytes());
            while (sendBuffer.hasRemaining()) {
                socketChannel.write(sendBuffer);
            }
            selectionKey.attach(null);
        }else {
            
            selectionKey.attach(mergeBuffer(oldBuffer, newBuffer));
        }

    }


    private String readLine(ByteBuffer buffer) throws UnsupportedEncodingException {
       
    	if(buffer.limit() > 0) {
    		return new String(Arrays.copyOf(buffer.array(), buffer.limit()));
    	} else {
    		return null;
    	}
    }

    public static ByteBuffer mergeBuffer(ByteBuffer oldBuffer,ByteBuffer newBuffer) {
        
        if (oldBuffer == null) {
            return newBuffer;
        }
        
        newBuffer.rewind();
        if (oldBuffer.remaining() > (newBuffer.limit()-newBuffer.position())) {
            return oldBuffer.put(newBuffer);
        }

        
        int oldSize = oldBuffer != null?oldBuffer.limit():0;
        int newSize = newBuffer != null?newBuffer.limit():0;
        ByteBuffer result = ByteBuffer.allocate(oldSize+newSize);

        result.put(Arrays.copyOfRange(oldBuffer.array(), 0, oldSize));
        result.put(Arrays.copyOfRange(newBuffer.array(), 0, newSize));

        return result;
    }

    private void startServer() {
        try {
            serverSocketChannel.bind(new InetSocketAddress(port));
            serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
            selectLoop();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }


    public static void main(String[] args) throws UnsupportedEncodingException {
        try {
            new NioServer(8888).startServer();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

