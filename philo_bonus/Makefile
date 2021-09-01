NAME		= philo_bonus
SHELL		= /bin/bash
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
SRCDIR		= ./srcs
SRCSUBDIR	= ./srcs/main_thread
LIBDIR		= ./libph
B_SRCDIR	= ./srcs_bonus
OBJDIR		= ./obj
INCLUDE		= ./includes
VPATH		= $(SRCDIR):$(SRCSUBDIR):$(LIBDIR):$(B_SRCDIR)
SRCS	=\
	./srcs/doctor.c\
	./srcs/main_proc/exit.c\
	./srcs/main_proc/fork_proc.c\
	./srcs/main_proc/main.c\
	./srcs/main_proc/philo_init.c\
	./srcs/main_proc/sem_init.c\
	./srcs/philosopher.c\

LIBSRCS	=\
	./libph/count_digits.c\
	./libph/ft_atoi_err.c\
	./libph/get_msec.c\
	./libph/get_usec.c\
	./libph/mtx_do_func.c\
	./libph/mymsleep.c\

B_SRCS	=\

OBJS	= $(shell basename -a $(SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	= $(shell basename -a $(SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')

# ifdef WITH_BONUS
# NAME	= philo_bonus
# OBJS	= $(shell basename -a $(B_SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# DEPENDS	= $(shell basename -a $(B_SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# endif

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : %.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo -e "	""\033[1;32m$@\033[0;39m"

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -lpthread -o $@
	@echo -e "\n\033[1;35m Generated\n	\033[0;39m\033[1;32m$@\033[0;39m"

clean	: rm_reloc
#	# @make b_clean WITH_BONUS=1

fclean	: clean rm_exec
#	@make b_fclean WITH_BONUS=1

# bonus	:
# 	@make WITH_BONUS=1

b_clean	: rm_reloc

b_fclean: rm_exec

rm_reloc:
	$(RM) $(OBJS) $(DEPENDS)

rm_exec	:
	$(RM) $(NAME)

re		: fclean all

add		:
	bash header.sh "$(SRCDIR)" $(INCLUDE)/philo_bonus.h
	bash header.sh "$(LIBDIR)" $(INCLUDE)/libph.h
	bash make.sh "$(SRCDIR)" SRCS
	bash make.sh "$(LIBDIR)" LIBSRCS
#bash make.sh "$(B_SRCDIR)" B_SRCS

norm	:
	@norminette | grep -v ': OK!' || \
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm: OK!';

.PHONY	: all clean fclean re bonus add norm rm_exec rm_reloc b_clean b_fclean