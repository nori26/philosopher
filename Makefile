NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
SRCDIR	= ./srcs
OBJDIR	= ./srcs/obj
SRCS	=\
	./srcs/test.c

OBJS	= $(shell echo $(SRCS:.c=.o) | awk -v s=$(SRCDIR) -v o=$(OBJDIR) '{sub(s, o); print $0}')
DEPENDS	= $(shell echo $(SRCS:.c=.d) | awk -v s=$(SRCDIR) -v o=$(OBJDIR) '{sub(s, o); print $0}')

all		: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME)	: $(OBJS)
	echo $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

add		:
	bash header.sh $(SRCDIR) philo.h
	bash make.sh $(SRCDIR) SRCS

clean	:
	$(RM) $(OBJS) $(B_OBJS) $(DEPENDS)

fclean	:
	$(RM) $(NAME) $(OBJS) $(DEPENDS)

re		: fclean all

.PHONY	: all clean fclean re add bonus