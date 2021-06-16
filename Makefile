# PROGRAM NAMES
SERVER		=	server
CLIENT		=	client

# COMPILER
CC			=	gcc

# FLAGS
CFLAGS		=	-Wall -Werror -Wextra

# HEADER
INC_DIR		=	./include

INC			=	-I $(INC_DIR)

# SOURCES
SRCS_DIR		=	./srcs

SRCS_SERVER	=	server.c \
				utils.c

SRCS_CLIENT	=	client.c \
				utils.c

# OBJECTS
OBJS_DIR				=	./objs
OBJS_CLIENT				=	$(addprefix $(OBJS_DIR)/,$(SRCS_CLIENT:.c=.o))
OBJS_SERVER				=	$(addprefix $(OBJS_DIR)/,$(SRCS_SERVER:.c=.o))

$(OBJS_DIR)/%.o		:	$(SRCS_DIR)/%.c
							$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all						:	$(SERVER) $(CLIENT)

objs					:
							mkdir -p $(OBJS_DIR)

$(SERVER)			:	objs $(OBJS_SERVER)
							$(CC) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT)			:	objs $(OBJS_CLIENT)
							$(CC) $(OBJS_CLIENT) -o $(CLIENT)

clean					:
							@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean					:	clean
							@rm -rf $(OBJS_DIR)
							@rm -f $(SERVER) $(CLIENT)

re						:	fclean all

.PHONY					:	all re clean fclean
