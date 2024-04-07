# Simple pygame program
# Import and initialize the pygame library

import pygame
from math import *

pygame.init()

TELA_ALTURA = 800
TELA_LARGURA = 800

# Set up the drawing window
screen = pygame.display.set_mode([TELA_LARGURA, TELA_ALTURA])

# Run until the user asks to quit
running = True

# origem será no meio da tela
v_origem = [TELA_LARGURA//2, TELA_ALTURA//2]


def modulo(v):
    ''' calcular modulo de vetor'''
    return (v[0]**2 + v[1]**2)**(1/2.0)


def unitario(v):
    m = modulo(v)
    return [v[0]/m, v[1]/m]


def cart_para_cg(v_entrada):
    """
    cart = coordenadas cartesianas
    cg = coordenanas na computação gráfica

    cg para cart ajusta as coordenadas de cartesiana para computação 
    gráfica

    coordenadas na computação
    gráfica possuem origem no canto superior esquerdo, x cresce para
    direita, y cresce para baixo.

    Essa função fará com que as coordenas de entrada sejam pensadas como
    origem no centro da tela, x cresce para direita, y cresce para esquerda

    as coordenadas de saída estarão no formato utilizado pelo pygame

    """
    return (int(v_origem[0] + v_entrada[0]), int(v_origem[1] + (-1) * v_entrada[1]))


def resolver2x2(a, b, c, d, e, f):
    # ax + by = c
    # dx + ey = f
    m = e * a - d * b
    print(f'm={m}')
    if m == 0:
        return None
    # IMPORTANTE! conferir as equações
    if a != 0:
        y = (a*f - d*c) / m
        x = (c - b*y) / a
    else:
        x = b*f-e*a
        y = (c - a*x) / b

    return (x, y)


def resolve_grau2(a, b, c):
    d = b*b - 4 * a * c
    if d < 0:
        return None
    elif d == 0:
        return b/(2*a)
    sd = d**(1/2)
    return ((-b-sd)/(2*a), (-b+sd)/(2*a))


def calc_reflexao(dir_n, dir_r):
    '''
        dir_n é a direção da normal
        dir_r é a direção do raio
        retorna direcao_unitaria
    '''
    dir_n = unitario(dir_n)
    dir_r = unitario(dir_r)
    tmp = dir_n[0] * dir_r[0] + dir_n[1] * dir_r[1]
    ref = [dir_r[0] - 2 * tmp * dir_n[0],
           dir_r[1] - 2 * tmp * dir_n[1]]
    return unitario(ref)


# centro da camera
v_camera = [-250, -250]
# vetor diretor do raio
v_raio = unitario([1, 0])
# variavel de controle para direção do raio
angulo = 0
# centro do objeto
v_objeto = [350, 50]
r_objeto = 50
# centro da luz
v_luz = [-100, 300]


# loop de jogo
while running:

    # capturar eventos
    # Did the user click the window close button?
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                running = False
            if event.key == pygame.K_DOWN:
                angulo += -pi/720
            if event.key == pygame.K_UP:
                angulo += +pi/720
            if event.key == pygame.K_PAGEDOWN:
                angulo += 120*-pi/720
            if event.key == pygame.K_PAGEUP:
                angulo += 120*+pi/720

            v_raio = (cos(angulo), sin(angulo))
            print(v_raio)

    # limpar a tela
    screen.fill((0, 0, 0))
    # Draw a solid blue circle in the center

    # desenhar eixos do plano cartesiano
    pygame.draw.line(screen, (25, 25, 25), (0, TELA_ALTURA//2),
                     (TELA_LARGURA, TELA_ALTURA//2), 1)
    pygame.draw.line(screen, (25, 25, 25), (TELA_LARGURA//2, 0),
                     (TELA_LARGURA//2, TELA_ALTURA), 1)

    # desenhar um circulo em torno do ponto central da camera
    pygame.draw.circle(screen, (25, 150, 50), cart_para_cg(v_camera),
                       25)
    # desenhar uma linha que representa a direção do raio, ela terá
    # 50 unidades de comprimento
    v_dir = unitario(v_raio)
    pygame.draw.line(screen, (25, 150, 50), cart_para_cg(v_camera),
                     cart_para_cg(
        (v_camera[0]+v_dir[0]*150, v_camera[0]+v_dir[1]*150)),
        1)

    # desenhar um circulo para representar o objeto
    pygame.draw.circle(screen, (150, 25, 50), cart_para_cg(v_objeto),
                       r_objeto)

    # desenhar um circulo para representar a iluminação
    pygame.draw.circle(screen, (200, 200, 200), cart_para_cg(v_luz),
                       25)

    # verificar a intersecção entre o raio e a reta da borda direita
    # vetor com a direção da borda direita
    dir_borda = unitario([0, TELA_LARGURA])
    org_borda = [TELA_LARGURA//2, -TELA_ALTURA//2]  # origem da borda

    dir_raio = unitario(v_raio)
    org_raio = v_camera

    a = dir_raio[0]
    b = - dir_borda[0]
    c = org_borda[0] - org_raio[0]

    d = dir_raio[1]
    e = - dir_borda[1]
    f = org_borda[1] - org_raio[1]

    inter = resolver2x2(a, b, c, d, e, f)
    if (inter is not None):
        print(inter)

    # primeira coordenada do inter possui a intersecao do raio com a borda
    pygame.draw.circle(screen, (50, 100, 200),
                       cart_para_cg((int(org_raio[0] + inter[0] * dir_raio[0]),
                                     int(org_raio[1] + inter[0] * dir_raio[1]))),
                       5)

    # segunda coordenada do inter possui a intersecao da borda com o raio
    pygame.draw.circle(screen, (200, 200, 40),
                       cart_para_cg((org_borda[0] + inter[1] * dir_borda[0],
                                     org_borda[1] + inter[1] * dir_borda[1])),
                       5)

    # testar se deve desenhar o raio até a borda, ou seja, se
    # inter1 < tamanho da borda
    if inter[1] >= 0 and inter[1] < TELA_ALTURA:
        ## Linha principal
        pygame.draw.line(screen, (25, 150, 50), cart_para_cg(v_camera),
                         cart_para_cg((org_borda[0] + inter[1] * dir_borda[0],
                                       org_borda[1] + inter[1] * dir_borda[1])), 1)

    a = dir_raio[0]*dir_raio[0] + dir_raio[1]*dir_raio[1]
    b = 2 * ((dir_raio[0] * (org_raio[0] - v_objeto[0])) +
             (dir_raio[1] * (org_raio[1] - v_objeto[1])))
    c = (org_raio[0] - v_objeto[0])*(org_raio[0] - v_objeto[0]) +\
        (org_raio[1] - v_objeto[1])*(org_raio[1] - v_objeto[1]) -\
        r_objeto**2

    d = resolve_grau2(a, b, c)

    if d is None:
        print('sem interseccao')
    else:

        if len(d) == 1:
            pygame.draw.circle(screen, (50, 100, 200),
                               cart_para_cg((org_raio[0] + d[0] * dir_raio[0],
                                             org_raio[1] + d[0] * dir_raio[1])), 5)
        else:
            pygame.draw.circle(screen, (50, 100, 200),
                               cart_para_cg((org_raio[0] + d[0] * dir_raio[0],
                                             org_raio[1] + d[0] * dir_raio[1])), 5)
            pygame.draw.circle(screen, (50, 100, 200),
                               cart_para_cg((org_raio[0] + d[1] * dir_raio[0],
                                             org_raio[1] + d[1] * dir_raio[1])), 5)

        # menor distancia
        d_menor = min(d[0], d[1])

        # ponto da esfera com a menor distancia
        pontoi = [org_raio[0] + d_menor * dir_raio[0],
                  org_raio[1] + d_menor * dir_raio[1]]

        # desenhar reta do centro do objeto ate a menor distancia
        pygame.draw.line(screen, (250, 250, 250),
                         cart_para_cg(v_objeto),
                         cart_para_cg(pontoi), 1)

        # vetor unitario do centro do objeto para a interseccao
        normal = unitario([pontoi[0] - v_objeto[0], 
                           pontoi[1] - v_objeto[1]])
        # perpendicular ao ponto de interseccao do raio
        v_perp = [-normal[1], normal[0]]
        ponto_a = [pontoi[0] + 50 * v_perp[0],
                   pontoi[1] + 50 * v_perp[1]]
        ponto_b = [pontoi[0] - 50 * v_perp[0],
                   pontoi[1] - 50 * v_perp[1]]

        pygame.draw.line(screen, (250, 250, 250),
                         cart_para_cg(ponto_a),
                         cart_para_cg(ponto_b), 1)

        ref = calc_reflexao(normal, dir_raio)

        # Desenha a linha do reflexo
        pygame.draw.line(screen, (40, 40, 250),
                         cart_para_cg(pontoi),
                         cart_para_cg((pontoi[0]+200*ref[0],
                                       pontoi[1]+200*ref[1])
                                      ), 1)

    # Flip the display
    pygame.display.flip()

# Done! Time to quit.

pygame.quit()
