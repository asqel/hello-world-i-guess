/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:57 by asqel             #+#    #+#             */
/*   Updated: 2024/07/31 08:47:30 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcodes.h"
#include "why.h"

void	cpu(const unsigned char *code)
{
	char	stack[STACK_SIZE];
	int		stack_top;

	stack_top = 0;
	while (*code != OPC_END)
		do_opcode(&code, stack, &stack_top);
}

int	main(void)
{
	const unsigned char	code[] = {OPC_END};

	cpu(code);
	return (0);
}
