# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:32:18 by bandre            #+#    #+#              #
#    Updated: 2017/03/15 18:46:32 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	make -C corewar_src
	make -C desassembleur_src
	make -C asm_src
	mv asm_src/asm .
	mv corewar_src/corewar .
	mv desassembleur_src/desassembleur .

clean:
	make clean -C corewar_src
	make clean -C desassembleur_src
	make clean -C asm_src

fclean:
	make fclean -C corewar_src
	make fclean -C desassembleur_src
	make fclean -C asm_src
	rm -f corewar
	rm -f asm
	rm -f desassembleur

re:
	rm -f corewar
	rm -f asm
	rm -f desassembleur
	make re -C corewar_src
	make re -C desassembleur_src
	make re -C asm_src
	mv asm_src/asm .
	mv corewar_src/corewar .
	mv desassembleur_src/desassembleur .
