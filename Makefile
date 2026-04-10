CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ircserv

DIR_MAIN = main
DIR_SRC  = src
CHANNEL_SRC = src_channels

FILES = \
    $(DIR_MAIN)/main.cpp \
    $(DIR_SRC)/server.cpp \
    $(DIR_SRC)/client.cpp \
    $(DIR_SRC)/utls.cpp \
    $(DIR_SRC)/authentication.cpp \
    $(CHANNEL_SRC)/managerchannel.cpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	./$(NAME) 4443 0000

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re