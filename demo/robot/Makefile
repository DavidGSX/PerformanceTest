#############################################################
#                                                           #
#                Makefile for SharpPerformanceRobot         #
#                Edit by honyliu 2015.07.23                 #
#############################################################


CC               = gcc -fPIC
CXX              = g++ -fPIC
AR               = ar


###编译标志###
C_FLAGS          =  -g 
CXX_FLAGS        =  -g 
C_SHARED = -shared 

#源代码程序根目录
ROOT_DIR=./
TCONNLIB_DIR=
#--------配置库文件---------------
#1、在这里配置库文件
#    静态库，ex: -L /usr/lib -lpthread   表示加入指定目录下静态库libpthread.a
#    动态库，ex:  -lpthread 表示加入动态库 libpthread.so
#2、把头文件放在src/include/xxx 目录下 或者在INC变量中指定头文件位置
#----------------------------------

LIB_STATIC =   -L../../lib -lspr   

LIB_DYNAMIC =  -lpthread

SRC_DIR = ../
OBJ_DIR = ../../tmp/obj/
TARGET_EXE= ../../bin/Robot
EXCLUDE_DIRS =


#在这里指定源文件的目录
SOURCE=$(wildcard ../../src/*.cpp)
SOURCE+=$(wildcard ./*.cpp)

#这里要跳过测试用的../scene/main.cpp
TEMP_SOURCE+=$(wildcard ../scene/*.cpp)
SCENE_MAIN = ../scene/main.cpp
SOURCE+=$(filter-out $(SCENE_MAIN),$(TEMP_SOURCE))
SOURCE+=$(wildcard *.cpp)

SRC=$(notdir $(SOURCE))
SRCOBJ=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(SRC))))
OBJS=$(addprefix $(OBJ_DIR), $(SRCOBJ))



TARGET=$(TARGET_EXE)

#在这里指定头文件的目录
INC+=  -I../../src/core/ -I../../src/ -I../../src/jsonCPP/dist/ -I../ -I../robot -I../scene/  -I../../src/tools/
INC+=  -I../../src/node/ -I../../src/node/messages  -I../../src/node/logic  -I../../src/GAPSLOGSVR/  -I../../src/api/   
INC+=  -I../../src/protocal/ -I../../src/protocal/base -I../../src/protocal/cmd  -I../../src/protocal/tdr

all:$(OBJS)
.PHONY:clean

#在这里也需要指定源文件的目录
$(OBJ_DIR)%.o: ../../src/%.cpp
	@$(CXX) $(INC)  $(C_FLAGS) -c  $< -o $@
	@echo   @$(CXX)  $(C_FLAGS) -c  $< -o $@
$(OBJ_DIR)%.o: %.cpp
	@$(CXX) $(INC)  $(C_FLAGS) -c  $< -o $@
	@echo   @$(CXX)  $(C_FLAGS) -c  $< -o $@
	
#test scene	
$(OBJ_DIR)%.o: ../scene/%.cpp
	@$(CXX) $(INC)  $(C_FLAGS) -c  $< -o $@
	@echo   @$(CXX)  $(C_FLAGS) -c  $< -o $@	
$(OBJ_DIR)%.o: %.c
	@$(CC) $(INC) $(C_FLAGS) -c $< -o $@
	@echo compile   $@
$(TARGET): $(OBJS)
	@$(CXX)  $(INC) $^ -o $@   -Wl,-Bstatic $(LIB_STATIC) -Wl,-Bdynamic $(LIB_DYNAMIC)
	@echo -e "Create $@"
	@echo $(CXX)   $^ -o $@

all: $(TARGET)

clean:
	@rm -f $(TARGET) $(OBJS)
	@echo rm *.o  $(TARGET) 
