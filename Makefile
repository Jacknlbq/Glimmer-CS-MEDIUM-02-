src = $(wildcard ./function/*.c) $(wildcard ./calculate/*.c)
obj = $(patsubst %.c, %.o, $(src))
ALL : task2.out
$(obj) : %.o : %.c
	gcc -c $< -o $@
task2.out : $(obj) task2.o
	gcc $^ -o $@
task2.o : ./main/task2.c
	gcc -c $< -o $@ 
clean :
	-rm -rf   $(obj) task2.o
