FLAGS = -Wall -Wextra

all: bin/2char \
     bin/calc \
     bin/char2 \
     bin/cmuck \
     bin/dec \
     bin/gituser \
     bin/haiku \
     bin/hex \
     bin/randnames \
     bin/randomize \
     bin/roll \
     bin/sge \
     bin/width \
     bin/zseq 

clean:
	rm -f bin/* ; > bin/.keep

bin/2char: 2char.c
	gcc $(FLAGS) -o bin/2char 2char.c

bin/calc: sh/calc.sh
	cp sh/calc.sh bin/calc ; chmod 0700 bin/calc

bin/char2: char2.c
	gcc $(FLAGS) -o bin/char2 char2.c

bin/cmuck: sh/cmuck.sh
	cp sh/cmuck.sh bin/cmuck ; chmod 0700 bin/cmuck

bin/dec: dec.c
	gcc $(FLAGS) -o bin/dec dec.c

bin/gituser: sh/gituser.sh
	cp sh/gituser.sh bin/gituser ; chmod 0700 bin/gituser

bin/haiku: haiku/haiku.cpp
	g++ $(FLAGS) -o bin/haiku haiku/haiku.cpp

bin/hex: hex.c
	gcc $(FLAGS) -o bin/hex hex.c

bin/randnames: randnames/randnames.cpp
	g++ $(FLAGS) -o bin/randnames randnames/randnames.cpp

bin/randomize: randomize.cpp
	g++ $(FLAGS) -o bin/randomize randomize.cpp

bin/roll: roll.cpp
	g++ $(FLAGS) -o bin/roll roll.cpp

bin/sge: sge.c
	gcc $(FLAGS) -o bin/sge sge.c

bin/width: width.cpp
	g++ $(FLAGS) -o bin/width width.cpp

bin/zseq: zseq.c
	gcc $(FLAGS) -o bin/zseq zseq.c

