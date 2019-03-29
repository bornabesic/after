all: compile

compile:
	gcc main.c -o after

clean:
	rm -rf ./after

