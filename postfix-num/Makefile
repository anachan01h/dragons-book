NAME = postfix-num

bin/$(NAME): src/$(NAME).c bin/
	gcc -o bin/$(NAME) src/$(NAME).c

bin/:
	mkdir bin

run: bin/$(NAME)
	./bin/$(NAME)