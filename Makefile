# PROGRAM NAMES
SERVER		=	server
CLIENT		=	client

BONUS_SERVER	= server_bonus
BONUS_CLIENT	= client_bonus

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

SRCS_SERVER_BONUS	=	server_bonus.c \
						utils.c

SRCS_CLIENT_BONUS	=	client_bonus.c \
						utils.c

# OBJECTS
OBJS_DIR				=	./objs
OBJS_CLIENT				=	$(addprefix $(OBJS_DIR)/,$(SRCS_CLIENT:.c=.o))
OBJS_SERVER				=	$(addprefix $(OBJS_DIR)/,$(SRCS_SERVER:.c=.o))

OBJS_CLIENT_BONUS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_CLIENT_BONUS:.c=.o))
OBJS_SERVER_BONUS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_SERVER_BONUS:.c=.o))

$(OBJS_DIR)/%.o			:	$(SRCS_DIR)/%.c
							$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all						:	$(SERVER) $(CLIENT)

bonus					:	$(BONUS_SERVER) $(BONUS_CLIENT)

objs					:
							mkdir -p $(OBJS_DIR)

$(SERVER)				:	objs $(OBJS_SERVER)
							$(CC) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT)				:	objs $(OBJS_CLIENT)
							$(CC) $(OBJS_CLIENT) -o $(CLIENT)

$(BONUS_SERVER)			:	objs $(OBJS_SERVER_BONUS)
							$(CC) $(OBJS_SERVER_BONUS) -o $(BONUS_SERVER)

$(BONUS_CLIENT)			:	objs $(OBJS_CLIENT_BONUS)
							$(CC) $(OBJS_CLIENT_BONUS) -o $(BONUS_CLIENT)

clean					:
							@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
							@rm -f $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean					:	clean
							@rm -rf $(OBJS_DIR)
							@rm -f $(SERVER) $(CLIENT)
							@rm -f $(BONUS_SERVER) $(BONUS_CLIENT)

re						:	fclean all

.PHONY					:	all re clean fclean
