/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   why.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:25:41 by asqel             #+#    #+#             */
/*   Updated: 2024/07/31 08:39:09 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHY_H
# define WHY_H

# include <stdio.h>

# define STACK_SIZE 0x1000

void	do_opcode(unsigned char **code, char stack[STACK_SIZE], int *stack_top);
void	do_add(unsigned char **code, char stack[STACK_SIZE], int *stack_top);
void	do_sub(unsigned char **code, char stack[STACK_SIZE], int *stack_top);
void	do_and(unsigned char **code, char stack[STACK_SIZE], int *stack_top);
void	do_not(unsigned char **code, char stack[STACK_SIZE], int *stack_top);

#endif