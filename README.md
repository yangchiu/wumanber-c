# wu-manber-string-matching
- Wu-Manber algorithm C implementation
- only for 7-bits ASCII
- minimum pattern length should greater than 3

#### Usage
execute make:
```python
$ make
# print
# $ make
# gcc -g -Wall -std=gnu99 -c main.c
# gcc -g -Wall -std=gnu99 -c ShiftTable.c
# gcc -g -Wall -std=gnu99 -c ShiftTableOperation.c
# gcc -g -Wall -std=gnu99 -c PrefixTable.c
# gcc -g -Wall -std=gnu99 -c PrefixTableOperation.c
# gcc -g -Wall -std=gnu99 -c WuManberOperation.c
# gcc -g -Wall -std=gnu99 -c RawOperation.c
# gcc -o a.out main.o ShiftTable.o ShiftTableOperation.o PrefixTable.o PrefixTableOperation.o WuManberOperation.o RawOperation.o
```
The first argument is the pattern file,
and the second argument is the content to be searched:
```python
$ ./a.out ./testcase/pattern2.txt ./testcase/content2.txt
# print
#  - Reading pattern file ...
# 
#  - Reading pattern file succeed.
# 
#  - Total 3 patterns:
#    - dimensional
#    - network
#    - autoencoder
# 
#  - Reading content file ...
# 
#  - Reading content file succeed.
# 
#  - Content:
#    - High-dimensional data can be converted to low-dimensional codes by training a multilayer
#  neural network with a small central layer to reconstruct high-dimensional input vectors. 
#  Gradient descent can be used for fine-tuning the weights in such ''autoencoder'' networks,
#   but this works well only if the initial weights are close to a good solution. We describe
#    an effective way of initializing the weights that allows deep autoencoder networks to learn 
#    low-dimensional codes that work much better than principal components analysis as a tool to 
#    reduce the dimensionality of data.
# 
#  - Min pattern length: 7
# 
#  - find dimensional at position 6 ~ 16
#  - find dimensional at position 47 ~ 57
#  - find network at position 97 ~ 103
#  - find dimensional at position 152 ~ 162
#  - find autoencoder at position 246 ~ 256
#  - find network at position 260 ~ 266
#  - find autoencoder at position 422 ~ 432
#  - find network at position 434 ~ 440
#  - find dimensional at position 456 ~ 466
#  - find dimensional at position 555 ~ 565
# 
#  - Done!
```
