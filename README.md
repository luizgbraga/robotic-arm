
# Introdução a Projetos de Engenharia (IPE) 1

Nessa disciplina do 3° período do Instituto Militar de Engenharia (IME), desenvolvemos um braço robótico capaz de transportar pequenas esferas de isopor de um suporte até um pequeno copo, onde eram depositadas.

## Sobre

Para isso, integramos Servo Motores a um braço robótico construído com palitos de sorvete, parafusos e brocas, de forma que haviam 3 Servos responsáveis pelo movimento tridimensional do braço e 1 Servo responsável pela abertura e fechamento da garra que transportava as pequenas esferas. É interessante destacar que o torque gerado pelo braço prejudicava o movimento dos Servos, que tremiam constantemente, impedindo o transporte seguro e preciso das esferas. A solução encontrada foi mover os Servos não para a posição indicada no potenciômetro, mas sim para a média aritmética das últimas dez posições registradas: essa mudança tornou o movimento do braço mais suave, aumentando muito sua precisão no transporte.
