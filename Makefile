NAME		= philo
SHELL		= /bin/bash
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
SRCDIR		= ./srcs
OBJDIR		= ./srcs/obj
INCLUDES	= ./includes
SRCS		=\
	./srcs/test.c\

# OBJS	= $(shell echo $(SRCS:.c=.o) | awk -v s=$(SRCDIR) -v o=$(OBJDIR) '{sub(s, o); print $0}')
#DEPENDS	= $(shell echo $(SRCS:.c=.d) | awk -v s=$(SRCDIR) -v o=$(OBJDIR) '{sub(s, o); print $0}')
OBJS		= $(OBJDIR)/$(shell basename -a $(SRCS:.c=.o))
DEPENDS		= $(OBJDIR)/$(shell basename -a $(SRCS:.c=.d))

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@ 

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -o $@

add		:
	bash header.sh $(SRCDIR) $(INCLUDES)/philo.h
	bash make.sh $(SRCDIR) SRCS

clean	:
	$(RM) $(OBJS) $(B_OBJS) $(DEPENDS)

fclean	:
	$(RM) $(NAME) $(OBJS) $(DEPENDS)

re		: fclean all

norm	:
	@[ -z "$(shell norminette | grep -v ': OK!' | tee /dev/stderr)" ] &&\
	printf '\x1b[1m\x1b[32m%s\x1b[39m\x1b[0m\n' 'Norm OK!';

.PHONY	: all clean fclean re add bonus