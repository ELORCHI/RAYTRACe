/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:10:55 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/20 11:14:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

typedef struct
{
	int a;
	int b;
}	asd;
int main()
{
    asd foo = {100, 200};
    unsigned char* bar = (void*)&foo;
    printf("%d\n", *(int*)(bar+offsetof(asd, a)));
	return 0;
}
