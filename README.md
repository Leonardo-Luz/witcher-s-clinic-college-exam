# witcher-s-clinic-college-exam
Projeto Final Algoritmos e programação - 1º Semestre

Clínica Geralt de Rivia

Como todos sabemos, Geralt de Rivia, antes conhecido como bruxo ou apenas Witcher, passou a vida criando
poções capazes de gerar grandes habilidades. Agora com uma idade já avançada e com poucos monstros na sua terra
conhecida como “o continente”, ele resolveu, junto com Cirila, abrir uma clínica para atender toda aquela pessoa enferma
que precisa de alguma poção mágica (medicamento).
Considerando a alta procura por pacientes, Cirila exigiu que o Geralt consiga um sistema para anotar os
tratamentos prescritos aos pacientes. Desta forma, todos os pacientes deverão ser cadastrados, assim como os
medicamentos e os médicos.
Dados necessários:

 Bruxo:
Nome, Especialidade.

 Poção:
Nome, Tipo (líquido ou comprimido).

 Paciente:
Nome, idade, altura.

 Tratamento:
Bruxo que prescreveu o tratamento, Paciente que realizará o tratamento, Medicamento utilizado, Dias
de tratamento, dosagem diária (quantidade de vezes no dia)

O que o programa deverá fazer:
<ol start="0">
 <li>Sair</li>
 <li>Listar Bruxos</li>
 <li>Cadastrar bruxo pelo código</li>
 <li>Excluir bruxo pelo código</li>
 <li>Listar Poções</li>
 <li>Cadastrar poção pelo código</li>
 <li>Excluir poção pelo código</li>
 <li>Listar Pacientes</li>
 <li>Cadastrar paciente pelo código</li>
 <li>Excluir paciente pelo código</li>
 <li>Listar tratamentos do paciente</li>
 <li>Listar pacientes do bruxo</li>
 <li>Iniciar tratamento</li>
 <li>Ampliar tratamento</li>
 <li>Apagar tratamento</li>
</ol>


O programa deverá prever erros e fazer validações para o bom funcionamento da clínica:

- Nunca acessar uma posição de array inválida (índices negativos ou maiores que o tamanho do array);
- Cadastrar bruxo apenas com códigos válidos (0 até tamanho do array-1); 
- Cadastrar poção apenas com códigos válidos (0 até tamanho do array-1);
- Cadastrar paciente apenas com códigos válidos (0 até tamanho do array-1);
- Iniciar tratamento apenas para bruxo cadastrados;
- Iniciar tratamento apenas para poção cadastradas;
- Iniciar tratamento apenas para paciente cadastrados;
- Não sobrescrever tratamentos;
- Listar apenas os tratamentos existentes;
- Não apagar bruxo, poção ou paciente se existir um tratamento relacionado;

