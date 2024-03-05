CLIENT = client.c
SERVER = server.c
CLOBJS = ${CLIENT:.c=.o}
SVOBJS = ${SERVER:.c=.o}

CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c
CLOBJS_BONUS = ${CLIENT_BONUS:.c=.o}
SVOBJS_BONUS = ${SERVER_BONUS:.c=.o}

LIBC = cc
LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${CLOBJS} ${SVOBJS}

${CLOBJS}:
	$(MAKE) --no-print-directory -C ./libft
	$(LIBC) $(FLAGS) $(CLIENT) $(LIBFT) -o client 

${SVOBJS}:
	$(MAKE) --no-print-directory -C ./libft
	${LIBC} ${FLAGS} ${SERVER} $(LIBFT) -o server

bonus: ${CLOBJS_BONUS} ${SVOBJS_BONUS}

${CLOBJS_BONUS}:
	$(MAKE) --no-print-directory -C ./libft
	$(LIBC) $(FLAGS) $(CLIENT_BONUS) $(LIBFT) -o client_bonus 


${SVOBJS_BONUS}:
	$(MAKE) --no-print-directory -C ./libft
	${LIBC} ${FLAGS} ${SERVER_BONUS} $(LIBFT) -o server_bonus


clean:
	${RM} client server

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	${RM} client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re

.SILENT: