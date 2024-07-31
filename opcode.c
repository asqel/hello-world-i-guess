/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:21 by asqel             #+#    #+#             */
/*   Updated: 2024/07/31 08:48:56 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcodes.h"
#include "why.h"

void	do_less(const unsigned char **code, char stack[STACK_SIZE]
	, int *stack_top)
{
	(*code)++;
	stack[*stack_top - 1] = (stack[*stack_top] < stack[*stack_top - 1]);
	(*stack_top)--;
}

void	do_eq(const unsigned char **code, char stack[STACK_SIZE]
	, int *stack_top)
{
	(*code)++;
	stack[*stack_top - 1] = (stack[*stack_top] == stack[*stack_top - 1]);
	(*stack_top)--;
}

void	do_opcode(const unsigned char **code, char stack[STACK_SIZE]
	, int *stack_top)
{
	if (**code == OPC_ADD)
		do_add(code, stack, stack_top);
	else if (**code == OPC_SUB)
		do_sub(code, stack, stack_top);
	else if (**code == OPC_AND)
		do_and(code, stack, stack_top);
	else if (**code == OPC_NOT)
		do_not(code, stack, stack_top);
	else if (**code == OPC_LESS)
		do_less(code, stack, stack_top);
	else if (**code == OPC_EQ)
		do_eq(code, stack, stack_top);
	else if (**code == OPC_DUP)
	{
		stack[*stack_top + 1] = stack[*stack_top];
		(*stack_top)++;
	}
	else if (**code == OPC_JMPIF)
		(*code) = (*code + *(*code + 1) * (!!stack[*stack_top])
				+ 2 * !stack[(*stack_top)--]);
	else if (**code == OPC_JMP)
		(*code) = *code + *(*code + 1);
	else
		do_opcode2(code, stack, stack_top);
}
