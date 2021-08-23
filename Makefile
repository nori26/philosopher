NAME		= philo
SHELL		= /bin/bash
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
SRCDIR		= ./srcs
LIBDIR		= ./libph
B_SRCDIR	= ./srcs_bonus
OBJDIR		= ./obj
INCLUDE		= ./includes
VPATH		= $(SRCDIR):$(LIBDIR):$(B_SRCDIR)
SRCS	=\
	./srcs/create_threads.c\
	./srcs/died.c\
	./srcs/doctor.c\
	./srcs/eat.c\
	./srcs/exit.c\
	./srcs/hungry.c\
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

B_SRCS	=\
	./srcs_bonus/main_bonus.c\

OBJS	= $(shell basename -a $(SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a $(SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')

ifdef WITH_BONUS
NAME	= philo_bonus
OBJS	= $(shell basename -a $(B_SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a $(B_SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
endif

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : %.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -lpthread -o $@

clean	:
	$(RM) $(OBJS) $(DEPENDS)
	make b_clean WITH_BONUS=1

fclean	: clean
	$(RM) $(NAME)
	make b_fclean WITH_BONUS=1

bonus	:
	make WITH_BONUS=1

b_clean	:
	$(RM) $(OBJS) $(DEPENDS)

b_fclean:
	$(RM) $(NAME)

re		: fclean all

add		:
	bash header.sh "$(SRCDIR)" $(INCLUDE)/philo.h
	bash header.sh "$(LIBDIR)" $(INCLUDE)/libph.h
	bash make.sh "$(SRCDIR)" SRCS
	bash make.sh "$(LIBDIR)" LIBSRCS
	bash make.sh "$(B_SRCDIR)" B_SRCS

norm	:
	@norminette | grep -v ': OK!' || \
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm: OK!';

.PHONY	: all clean fclean re bonus add norm