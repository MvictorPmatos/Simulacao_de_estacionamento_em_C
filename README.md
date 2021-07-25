[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=4717889&assignment_repo_type=AssignmentRepo)
# [RELATÓRIO] SEGUNDA CHAMADA - PROBLEMA 1

<h2>1. INTRODUÇÃO.</h2>

<h5 align="justify">O problema 1 consiste em um estacionamento autônomo, onde seu funcionamento é descrito no documento Segunda Chamada Problema 1 disponibilizado pelo professor Antônio Apolinário. Este relatório contém a descrição de como é a solução do problema e todos os pontos críticos para elaboração do programa. É importante lembrar que a solução foi construída com embasamento adquirido da disciplina de Estrutura de Dados e Algoritmos I.</h5>

<h2>2. SOLUÇÃO DO PROBLEMA.</h2>

<h5 align="justify"> A solução do problema foi construída tendo como referência o documento já citado e algumas imagens retiradas do google. Uma das imagens está anexada a seguir:</h5>
<img   src="https://austin.culturemap.com/thumbnail/600x600/photos/2013/07/24/full-parking-lot_154506.jpg">
<h5 align="justify">A ideia principal era alocação dos carros um após o outro em linhas adjacentes. E para a retirada de um carro, deveria haver a transferência de todos os carros da frente para uma área de manobra. O carro a ser retirado ía para última vaga da área de manobra, na qual essa última vaga é justamente a saída, portanto, o carro na vaga final era removido do estacionamento, e por fim, todos os carros alocados na área de manobra eram transferidos para sua linha original respeitando a mesma ordem.</h5>

<h2>3. PROGRAMA.</h2>
<h4>3.1. Estrutura de Dados. </h4>
<h5 align="justify"> Para construção do programa foram usados, de forma resumida, pilhas. Abordando uma maior especificidade, para a elaboração das linhas de estacionamento, foi usado uma array com n pilhas. Já para a área de manobra foi usada uma uma array para implementação de uma única pilha.

Entrando em mais detalhes sobre a elaboração das linhas do estacionamento, podemos dizer que a implementação completa conta não só com 1 array, mas com 4 arrays totais. São elas: arr, top, next, numEl. Arr é responsável por guardar as pilhas, top por guardar o topo de cada pilha, next por guardar o próximo item de arr e numEl por guardar o número de elementos de cada pilha.
 
Foi escolhido uma pilha justamente pelo comportamento do estacionamento, onde a cada entrada por linha, o carro é estacionado de forma a não deixar espaços vagos nas linhas. O que implica uma inversão na ordem, já que os primeiros a entrarem no estacionamento ficam alocados nas vagas que futuramente podem ser fechadas por outros carros, levando a essas mesmas vagas serem consideradas as “últimas” da linha. Tendo isso em vista, o comportamento de saída seria last in - first out.

Falando agora sobre a área de manobra, a pilha também é uma boa pedida aqui, já que todas vez que precisamos transferir carros da frente de uma linha para a área de manobra, implica também uma inversão, já que o primeiro a sair da linha é alocado na “primeira” vaga da área, então esse precisa ser o último a sair para que a ordem da linha original seja conservada. Portanto esse também é um comportamento last in - first out.</h5>

<h4>3.2 Pontos Críticos do Programa. </h4>
<h5 align = "justify"> Os pontos críticos são as soluções dadas aos pequenos problemas que aparecem durante a resolução que, quando juntas, são essenciais para o pleno funcionamento do programa.

O primeiro ponto a ser comentado são os métodos. A inserção nas linhas envolve um atributo chamado free. Esse atributo guarda a próxima posição livre da arr. Após guardar o valor de free em uma variável, atualizamos seu valor com a array next. O valor de next é atualizado para o topo da linha e o topo da linha, em seguida recebe a variável que guarda o antigo valor de free. Por fim, atualizamos arr usando essa mesma variável já mencionada como posição. A lógica para pop segue princípios parecidos.

Outro ponto interessante de mencionar é a identificação dos veículos. Visualmente falando, os veículos são representados por placas. Tais placas consistem em uma string de 3 letras e 4 números. Porém, se tratando de interação com o programa, é usado sua posição na linha, sendo de 1 até n, para retirar veículos. É bom mencionar que a criação de placas se dá de forma aleatória pela função plateGenerator.

Como já dito, a interação de remoção se dá pela posição do carro. Dessa forma, temos laços de repetição que recebem como um parâmetro de parada, a posição do carro, guardada no programa pela variável veic. Dentro desses laços é chamada a inserção dos veículos na área de manobra e logo em seguida é solicitado o pop da linha. Para reinserção a lógica é similar, tendo diferença pela inserção na linha e em seguida o pop da área de manobra.</h5>

<h4>3.3 Rodando o Programa.</h4>
<h5 align = "justify">A construção do programa se deu em Windows 10, com o editor de código Visual Studio Code em ambiente cmd. Foi usado o mingw32-make para utilização de um makefile, com adaptação para funcionamento usando apenas a linha $ make para compilar. Para executar o .exe, usa-se parking.

Para começo do programa, é gerado aleatoriamente um número de linhas de 2 a 5. Nesse ponto é mostrado as linhas e os carros e em seguida é pedido para o usuário se ele deseja estacionar ou retirar algum carro. Como o programa, no início gera carros o suficiente para preencher todas as vagas, caso você tente estacionar algum, ele dará o aviso que a linha está cheia.
 
Ao pressionar para retirar, ele pedirá pela linha e logo em seguida pela posição do carro. Após isso ele mandará os carros da frente para a área de manobra, e depois retornará os carros para a linha original sem o carro que foi pedido para ser retirado, já que esse carro foi para a saída. Por fim, ele pergunta se o usuário deseja continuar rodando o programa ou não. Caso sim, ele retorna a pergunta inicial, nesse ponto já é possível estacionar ou retirar, já que existe uma linha com vaga desocupada.

Caso escolha estacionar, ele perguntará a linha e automaticamente gerará um carro com placa aleatória e fará a inserção do carro na linha escolhida. Aqui ele fará novamente a pergunta se o usuário deseja continuar rodando o programa.</h5>

<h2>4. CONCLUSÃO.</h2>
<h5 align = "justify">Portanto, é possível verificar o bom funcionamento do programa e seu cumprimento com os requisitos-chave do problema. Abrindo um parênteses para uma opinião pessoal sobre o projeto, eu posso dizer que gostei muito da ideia, já que se encaixa justamente com minha graduação (Engenharia de Controle e Automação), o que me motivou muito mais a criar uma resolução para o problema. Além disso, esse método adotado pelo professor Apolinário é simplesmente muito proveitoso, para de fato buscar entender as utilidades reais das estruturas de dados e dos algoritmos que nos foram passados na disciplina.</h5>
