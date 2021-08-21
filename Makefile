NAME	= philo
SHELL	= /bin/bash
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP - O3
SRCDIR	= ./srcs
LIBDIR	= ./libph
OBJDIR	= ./obj
INCLUDE	= ./includes
VPATH	= $(SRCDIR):$(LIBDIR)
SRCS	=\
	./srcs/died.c\
	./srcs/doctor.c\
	./srcs/eat.c\
	./srcs/exit.c\
	./srcs/life.c\
	./srcs/philo.c\
	./srcs/take_a_fork.c\
	./srcs/threads_utils.c\
	./libph/count_digits.c\
	./libph/ft_atoi_err.c\
	./libph/get_msec.c\
	./libph/mtx_do_func.c\
	./libph/mymsleep.c\

OBJS	= $(shell basename -a  $(SRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a  $(SRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : %.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -lpthread -o $@

clean	:
	$(RM) $(OBJS) $(B_OBJS) $(DEPENDS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

add		:
	bash header.sh "$(SRCDIR) $(LIBDIR)" $(INCLUDE)/philo.h
	bash make.sh "$(SRCDIR) $(LIBDIR)" SRCS

norm	:
	@norminette | grep -v ': OK!' || \
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm: OK!';

.PHONY	: all clean fclean re bonus add norm