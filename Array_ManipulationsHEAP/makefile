output: main.o
	$(CXX) $< -o $@
%.o: %.cpp
	@printf "compiling %s", $<
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm*.o $@
