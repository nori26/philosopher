NAME	= philo
SHELL	= /bin/bash
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
SRCDIR	= ./srcs
LIBDIR	= ./srcs/libphilo
OBJDIR	= ./obj
INCLUDE	= ./includes
VPATH	= $(SRCDIR):$(LIBDIR)
SRCS	=\
	./srcs/libphilo/ft_atoi_err.c\
	./srcs/philo.c\

OBJS	= $(shell basename -a  $(SRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a  $(SRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : %.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

test:
	echo $(OBJS)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -o $@

clean	:
	$(RM) $(OBJS) $(B_OBJS) $(DEPENDS)

fclean	:
	$(RM) $(NAME) $(OBJS) $(DEPENDS)

re		: fclean all

add		:
	bash header.sh $(SRCDIR) $(INCLUDE)/philo.h
	bash make.sh $(SRCDIR) SRCS

norm	:
	@norminette | grep -v ': OK!' || \
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm: OK!';

.PHONY	: all clean fclean re bonus add norm