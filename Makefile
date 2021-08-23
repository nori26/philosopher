NAME	= philo
SHELL	= /bin/bash
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
SRCDIR	= ./srcs
LIBDIR	= ./libph
OBJDIR	= ./obj
INCLUDE	= ./includes
VPATH	= $(SRCDIR):$(LIBDIR)
SRCS	=\
	./srcs/create_threads.c\
	./srcs/died.c\
	./srcs/doctor.c\
	./srcs/eat.c\
	./srcs/exit.c\
	./srcs/hugry.c\
	./srcs/main.c\
	./srcs/philosopher.c\
	./srcs/philo_init.c\
	./srcs/print.c\
	./srcs/sleep_think.c\
	./srcs/take_a_fork.c\

LIBSRCS	=\
	./libph/count_digits.c\
	./libph/ft_atoi_err.c\
	./libph/get_msec.c\
	./libph/get_usec.c\
	./libph/mtx_do_func.c\
	./libph/mymsleep.c\

OBJS	= $(shell basename -a $(SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a $(SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')

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
	bash header.sh "$(SRCDIR)" $(INCLUDE)/philo.h
	bash header.sh "$(LIBDIR)" $(INCLUDE)/libph.h
	bash make.sh "$(SRCDIR)" SRCS
	bash make.sh "$(LIBDIR)" LIBSRCS

norm	:
	@norminette | grep -v ': OK!' || \
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm: OK!';

.PHONY	: all clean fclean re bonus add norm