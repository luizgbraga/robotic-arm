
# Introdução a Projetos de Engenharia (IPE) 1

Nessa disciplina do 3° período do Instituto Militar de Engenharia (IME), desenvolvemos um braço robótico capaz de transportar pequenas esferas de isopor de um suporte até um pequeno copo, onde eram depositadas.

## Sobre

Para isso, integramos Servo Motores a um braço robótico construído com palitos de sorvete, parafusos e brocas, de forma que haviam três Servo Motores responsáveis pelo movimento tridimensional do braço e um Servo Motor responsável pela abertura e fechamento da garra que transportava as pequenas esferas. 

É interessante destacar que por consequência da simplicidade dos Servo Motores, tanto o torque gerado pelo braço quanto a leitura imprecisa dos potenciômetros os faziam tremer constantemente, prejudicando a precisão no transporte das esferas. A solução encontrada foi alterar a função responsável pelo movimento dos Servo Motores: em vez de deslocá-los para a posição indicada no potenciômetro, agora os Servo Motores moviam-se para a média aritmética das dez últimas medições do potenciômetro. Com isso, o movimento do braço tornou-se mais suave, aumentando consideravelmente a precisão e segurança do transporte.
