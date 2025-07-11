# sums666
This program searches a wordlist for words who's characters' decimal ascii values sum to 666 and saves them to a file.<br /><br />
I have included a word list `words.txt` and the file `sums666.txt` which lists the words in `words.txt` who's characters decimal ascii values sum to 666.<br /><br />
The sum excludes the null character (`\0`) and the newline character (`\n`).<br /><br />

`Preterist theologians typically support the interpretation that 666 is the numerical equivalent of the name and title Nero Caesar (Roman Emperor 54–68 AD).` - <https://en.wikipedia.org/wiki/Number_of_the_beast> <br /><br />
I have used the ascii decimal equivalent. - <https://www.ascii-code.com/> <br /><br />

Dependencies:
 - gcc
<br />

To regenerate sums666.txt, run the following:
<br />
```
git clone https://github.com/RichTGale/sums666.git
```

```
cd sums666
```

```
chmod +x run.sh
```

```
./run.sh
```
To use your own word list, place your wordlist (e.g. `my_wordlist.txt`) into the root folder of this repo (`/path/to/sums666/my_wordlist.txt`). Then run the following:
```
gcc -o sums666 mycutils.h mycutils.c sums666.c
```

```
./sums666 my_wordlist.txt 666words.txt
```
