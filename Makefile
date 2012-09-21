USER_DIR = .

clean:
	rm -rf *.o *.a tests game

game:
	$(CXX) -o $@ $(USER_DIR)/main.cpp

