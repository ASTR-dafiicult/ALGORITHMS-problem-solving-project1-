file = project_1.c

display:
	@echo "project: $(file)"
	@echo "PATH = $(PATH)"

all: display
	gcc $(file) -Wall -Wextra -Werror -o cprogram

build:
	gcc $(file) -o cproject1

clean:
	@rm -f cprogram cproject1
	@clear