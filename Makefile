TARGET := canon
CC := c++ -std=c++98
FLAGS := -Wall -Wextra -Werror
SRCDIR		:=	./srcs
SRCEXT      := cpp
OS	:= $(shell uname)
SRCS := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")

ifeq ($(shell test -e /bin/zsh && echo -n yes),yes)
SHELL := /bin/zsh
else
SHELL := /bin/bash
endif

all: $(TARGET)

$(TARGET):
	$(CC) $(FLAGS) $(SRCS) -o $(TARGET)

install: $(TARGET)
	sudo mv $(TARGET) /usr/bin/
	@echo -e "\033[0;32mAll done !\033[0m"

school: $(TARGET)
	mkdir ~/.$(TARGET) && mv $(TARGET) ~/.$(TARGET)
	@if [[ $(SHELL) == "/bin/zsh" ]];then \
		echo "alias canon=\"~/.canon/canon\"" >> ~/.zshrc; \
		echo -e "\033[0;32mAll done ! Now open another shell or use source ~/.zshrc to use canon\033[0m"; \
	else \
		echo "alias canon=\"~/.canon/canon\"" >> ~/.bashrc \
		echo -e "\033[0;32mAll done ! Now open another shell or use source ~/.bashrc to use canon\033[0m"; \
	fi;
	
clean:
	rm $(TARGET)

fclean: clean

re: fclean all

.PHONY:	clean fclean all re