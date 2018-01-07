APP=a
$(APP): global.o
	@gcc -pthread -O1 -o $@ $^
	@echo Makedone!

debug: global.o
	@gcc -pthread -g -o $@ $^
	@echo Makedone!
	@echo DEBUG_VERSION

global.o: global.c
	@gcc -c $^ 

clean:
	@rm -f *.o $(APP)
