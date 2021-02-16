NAME = minirt.a

SRCS = camera.c color.c intersection.c light_and_shading.c light.c main.c shadow.c transformations.c \

OBJS = camera.o color.o intersection.o light_and_shading.o  light.o  main.o shadow.c transformations.o \

all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : 
	rm -rf $(NAME)

re : fclean all