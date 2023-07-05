# Crypt_and_DeCrypt_text
The fifth laboratory work in the first year of the Faculty of Mathematics of YarSU on the basics of programming in C++

In all tasks, we process the text in Russian. It is advisable to take your favorite book or an excerpt from it. We pre-process the texts (remove the empty lines at the beginning and end of the text, the table of contents, check that the first page of the text is meaningful).

FIRST TASK:

In order to facilitate decryption, we encode only letters with a simple replacement cipher, leaving everything else as it is. We do not encode the letter (russian Ё), we leave it as it is.

Encrypt the original text using a simple replacement algorithm. a. the text should be read from the file, b. the encrypted text should be written to the file.
Decrypt your text, make sure that the decrypted text matches the original one.
Transfer both texts to the teacher by naming the file Ivanov.txt and IvanovCrypt.txt .
In first task(laba_5_1, funcs, menu) I had to do: Cyclic shift of the alphabet to the left by K positions, where K is equal to the remainder of dividing the number of characters in the first line of the text by 10.

SECOND TASK:

You need to take some original text and perform a frequency analysis of the characters, that is, find out how many times each character occurs in the text. It is necessary to take into account the space, punctuation marks, uppercase and lowercase letters of the Russian alphabet. For each character, you need to output the frequency of its appearance in the text. Based on this analysis or slightly modifying it, complete the task according to the options. If you need to determine the "five most rare letters" in the options task, then it is also important to output the frequency for each of these letters and the AVERAGE frequency of LETTERS (not characters).

In second task(laba_5_2, funcs_2, menu_2) I had to do: What letter does a sentence most often begin with? Least often?
