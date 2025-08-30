FLAGS = -Wall -Wextra

all: bin/80 \
     bin/2char \
     bin/bytes \
     bin/calc \
     bin/char2 \
     bin/cmuck \
     bin/dec \
     bin/fjson \
     bin/gituser \
     bin/haiku \
     bin/hex \
     bin/jgr \
     bin/junknames \
     bin/keyme \
     bin/lcat \
     bin/randnames \
     bin/randomize \
     bin/roll \
     bin/sge \
     bin/wakeup \
     bin/width \
     bin/zseq 

clean:
	rm -f bin/* ; > bin/.keep

bin/80: 80.cpp
	g++ $(FLAGS) -o bin/80 80.cpp 

bin/2char: 2char.c
	gcc $(FLAGS) -o bin/2char 2char.c

bin/bytes: bytes.c
	gcc $(FLAGS) -o bin/bytes bytes.c

bin/calc: sh/calc.sh
	cp sh/calc.sh bin/calc ; chmod +x bin/calc

bin/char2: char2.c
	gcc $(FLAGS) -o bin/char2 char2.c

bin/cmuck: sh/cmuck.sh
	cp sh/cmuck.sh bin/cmuck ; chmod +x bin/cmuck

bin/dec: dec.c
	gcc $(FLAGS) -o bin/dec dec.c

bin/fjson: fjson/fjson.cpp fjson/json.hpp
	g++ $(FLAGS) -o bin/fjson fjson/fjson.cpp

bin/gituser: sh/gituser.sh
	cp sh/gituser.sh bin/gituser ; chmod +x bin/gituser

bin/haiku: haiku/haiku.cpp haiku/haiku_bits.hpp
	g++ $(FLAGS) -o bin/haiku haiku/haiku.cpp

bin/hex: hex.c
	gcc $(FLAGS) -o bin/hex hex.c

bin/jgr: sh/jgr.sh
	cp sh/jgr.sh bin/jgr ; chmod +x bin/jgr

bin/junknames: junknames.cpp
	g++ $(FLAGS) -o bin/junknames junknames.cpp

bin/keyme: sh/keyme.sh
	cp sh/keyme.sh bin/keyme ; chmod +x bin/keyme

bin/lcat: lcat.cpp 
	g++ $(FLAGS) -o bin/lcat lcat.cpp

bin/randnames: randnames/randnames.cpp randnames/names.hpp
	g++ $(FLAGS) -o bin/randnames randnames/randnames.cpp

bin/randomize: randomize.cpp
	g++ $(FLAGS) -o bin/randomize randomize.cpp

bin/roll: roll.cpp
	g++ $(FLAGS) -o bin/roll roll.cpp

bin/sge: sge.c
	gcc $(FLAGS) -o bin/sge sge.c

bin/wakeup: wakeup.cpp
	g++ $(FLAGS) -o bin/wakeup wakeup.cpp

bin/width: width.cpp
	g++ $(FLAGS) -o bin/width width.cpp

bin/zseq: zseq.c
	gcc $(FLAGS) -o bin/zseq zseq.c

