## Hanged Bunny Studio Library ------    ---  -- --- -    ---  --    - -- -   -
## Hanged Bunny Studio 2014-2016 ----- -- - -- -  -  -- -- - -- --  -- -- -- --
## ----------------------------------- -- -    - - - -- -- - -- ---- -    -- --
## ----------------------------------    -- -- - --- -    ---  --   -- -- -   -
## ----------------------------------------------------------------------------

## ----------------------------------------------------------------------------
## Configuration --------------------------------------------------------------

  MOD		=	game.exe
  BIN		=	game.exe
  FLAG		=	-W -Wall -std=gnu++2a -g -g3 -ggdb

  INCLUDE	=	-I./ -I./include/
  SRC		=	$(wildcard */*.cpp) $(wildcard */*/*.cpp)
  OBJ		=	$(SRC:.cpp=.o)
  LIBPATH	=	-L${HOME}/.froot/lib/

  ## Rules ------------------------------------------------------------------
  all:		bin
  bin:		$(OBJ)
		@b++ $(OBJ) -o $(BIN) $(LIBPATH) $(FLAG)
		@echo "[OUT] " $(BIN)
		@echo $(BIN) | tr '[:lower:]' '[:upper:]'
  .cpp.o:
		@b++ $(INCLUDE) $(FLAG) -c $< -o $@
		@echo "[BUNNYCC]" $<
  clean:
		@rm -f $(OBJ)
		@rm -f $(shell find ./ -name "*~")
  fclean:	clean
		@rm -f $(BIN)
  re:		fclean all

## ----------------------------------------------------------------------------
## MISC -----------------------------------------------------------------------

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o
