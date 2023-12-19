TARGET				=	planetgs

CXX						= c++
CXXFLAGS			=	-I./lib/sfml/2.6.1/include -I./src -std=c++11

LDFLAGS				=	-L./lib/sfml/2.6.1/lib -Wl,-rpath,./lib/sfml/2.6.1/lib
LDLIBS				=	-lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system 



SRC_DIR				=	./src
PGS_DIR				=	$(SRC_DIR)/pgs


OBJ_DIR				=	./obj

CLANGD_GEN		=	./clangd_gen.sh

SRC_FILES			=	$(SRC_DIR)/main.cpp

OBJ_FILES			=	$(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

PCH						=	$(PGS_DIR)/common.hpp.gch
PCH_SRC				=	$(PGS_DIR)/common.hpp






all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@

pch : $(PCH)

$(PCH) : $(PCH_SRC)
	$(CXX) $(CXXFLAGS) -x c++-header -o $@ $<



$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(PCH)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -include-pch $(PCH) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET) $(PCH)

clangd :
	/bin/bash $(CLANGD_GEN)

re : clean
	make all

.PHONY: all clean clangd re