NAME = miniRT

SRCS = srcs/camera.c srcs/color.c srcs/save.c srcs/light_and_shading.c srcs/light.c srcs/main.c srcs/shadow.c srcs/transformations.c \
		parsing/ambient.c	parsing/free.c parsing/get_color.c parsing/get_scalar.c parsing/get_vector.c parsing/atof.c \
		parsing/free_globals.c  parsing/get_cylinders.c parsing/get_sphere.c parsing/ft_int_size.c parsing/get_light.c \
		parsing/get_squares.c parsing/is_float.c parsing/resolution.c parsing/count_params.c parsing/get_camera.c parsing/get_plans.c \
		parsing/get_traingle.c parsing/is_rt.c parsing/chec_normal.c\
		parsing/gnl/get_next_line.c parsing/gnl/get_next_line_utils.c \
		parsing/libft/ft_atoi.c parsing/libft/ft_strlen.c parsing/libft/ft_isdigit.c parsing/libft/ft_memcpy.c parsing/libft/ft_split.c \
		parsing/libft/ft_strdup.c parsing/libft/ft_strncmp.c \
		helpers.c last_main.c \
		maths/cofactors.c   maths/debug.c maths/identity_mat.c maths/matrix_products.c maths/products.c maths/subb_mat3x3.c \
		maths/trans.c maths/vectors2.c maths/creat_mat.c maths/debug2.c maths/invers.c maths/normaliz.c maths/quadratic.c \
		maths/subb_mat4x4.c maths/vectors.c \
		ray/ray.c cylinder/cylinder.c plan/ray_plan_intersection.c square/square.c triangle/tr.c sphere/sphere.c \
		sphere/utils.c

OBJS = srcs/camera.o srcs/color.o srcs/save.o srcs/light_and_shading.o srcs/light.o srcs/main.o srcs/shadow.o srcs/transformations.o \
		parsing/ambient.o	parsing/free.o parsing/get_color.o parsing/get_scalar.o parsing/get_vector.o parsing/atof.o \
		parsing/free_globals.o  parsing/get_cylinders.o parsing/get_sphere.o parsing/ft_int_size.o parsing/get_light.o \
		parsing/get_squares.o parsing/is_float.o parsing/resolution.o parsing/count_params.o parsing/get_camera.o parsing/get_plans.o \
		parsing/get_traingle.o parsing/is_rt.o parsing/chec_normal.o\
		parsing/gnl/get_next_line.o parsing/gnl/get_next_line_utils.o \
		parsing/libft/ft_atoi.o parsing/libft/ft_strlen.o parsing/libft/ft_isdigit.o parsing/libft/ft_memcpy.o parsing/libft/ft_split.o \
		parsing/libft/ft_strdup.o parsing/libft/ft_strncmp.o \
		helpers.o last_main.o \
		maths/cofactors.o   maths/debug.o maths/identity_mat.o maths/matrix_products.o maths/products.o maths/subb_mat3x3.o \
		maths/trans.o maths/vectors2.o maths/creat_mat.o maths/debug2.o maths/invers.o maths/normaliz.o maths/quadratic.o \
		maths/subb_mat4x4.o maths/vectors.o \
		ray/ray.o cylinder/cylinder.o plan/ray_plan_intersection.o square/square.o triangle/tr.o sphere/sphere.o \
		sphere/utils.o

all : $(NAME)

$(OBJS) : $(SRCS)
$(NAME) : $(OBJS)
	gcc -Wall -Werror -Wextra -o miniRT -framework OpenGL -framework AppKit -lmlx $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all