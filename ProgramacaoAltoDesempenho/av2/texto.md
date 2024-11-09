# Programação para GPU com CuPy


## Introdução
Inicialmente, as GPUs (Graphic Processing Units) eram utilizadas apenas para a área da computação gráfica, sendo responsável por transferir as imagens do computador para o dispositivo de sáida. Entretanto, com o avanço da computação, perceberam que as GPUs conseguem processar muitas imagens por segundo a mais que a própria CPU (Central Processing Unit) e, a partir disso, começou-se a utilizar a GPU para processar grandes quantidades de dados em formato de imagens, chamando-a de GPGPU (General-Purpose computing on Graphics Processing Units).

Sabendo disso, a NVIDIA criou o CUDA^1 (Compute Unified Device Architecture), que é uma API (Application Programming Interface) cujo objetivo é o de facilitar o desenvolvimento de aplicações utilizando a GPU. 

Com isso, a Preferred Networks, em parceria com a NVIDIA e a Brookhaven, criou a biblioteca CuPy^2 para o Python. Esta biblioteca utiliza as bibliotecas do CUDA toolkit (cuBLAS, cuRAND, cuSOLVER, cuSPARSE, cuFFT, cuDNN e NCCL) para poder utilizar todo o poder da GPU. Além disso, o CuPy é open-source e compatível com as bibliotecas NumPy e SciPy.

## CUDA Cores
Para facilitar a programação em GPU, a NVIDIA criou o CUDA

## Referências
https://cupy.dev/

https://developer.nvidia.com/cuda-toolkit

http://learningsys.org/nips17/assets/papers/paper_16.pdf
