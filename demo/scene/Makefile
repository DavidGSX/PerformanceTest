#############################################################
#                                                           #
#                Makefile for SharpPerformanceRobot         #
#                Edit by honyliu 2015.07.23                 #
#############################################################


CC               = gcc
CXX              = g++
AR               = ar

###编译标志###
C_FLAGS          =  -g 
CXX_FLAGS        =  -g 
C_SHARED = -shared 

LIB_DIR=

LIB_STATIC =  
LIB_DYNAMIC = 

CRT_DIR = ../
OBJ_DIR = ../../tmp/obj_test/
TARGET_EXE= sceneTest


SOURCE=$(wildcard ./*.cpp)
#在这里指定源文件的目录
#例：
#SOURCE+=$(wildcard ../other/*.cpp)

SRC=$(notdir $(SOURCE))
SRCOBJ=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(SRC))))
OBJS=$(addprefix $(OBJ_DIR), $(SRCOBJ))


TARGET=$(TARGET_EXE)

#在这里指定头文件的目录
#例：
#INC+=-I../other/
INC+= -I../scene/

all:$(OBJS)
.PHONY:clean

#在这里也要指定源文件的目录
#例如：
#$(OBJ_DIR)%.o: other/%.cpp
#	@$(CXX) $(INC)  $(C_FLAGS) -c  $< -o $@
#	@echo   @$(CXX)  $(C_FLAGS) -c  $< -o $@
$(OBJ_DIR)%.o: %.cpp
	@$(CXX) $(INC)  $(C_FLAGS) -c  $< -o $@
	@echo   @$(CXX)  $(C_FLAGS) -c  $< -o $@
$(OBJ_DIR)%.o: %.c
	@$(CC) $(INC) $(C_FLAGS) -c $< -o $@
	@echo compile   $@
$(OBJ_DIR)%.o: %.cc
	@$(CXX) $(INC) $(C_FLAGS) -c $< -o $@
	@echo compile   $@
$(TARGET): $(OBJS)
	@$(CXX)  $(INC) $^ -o $@   -Wl,-Bstatic $(LIB_STATIC) -Wl,-Bdynamic $(LIB_DYNAMIC)
	@echo -e "Create $@"
	@echo $(CXX)   $^ -o $@

all: $(TARGET)

clean:
	@rm -f $(TARGET) $(OBJS)
	@echo rm *.o  $(TARGET) 
