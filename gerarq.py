from random import *
from collections import Counter
path = "/home/noedelima/Documentos/11 - Arquivos e Utilitários Diversos/workspace/EDA-IC-Uff/src/vendas.txt"
dados_venda = []
total_vendido = []
with open(path, "w") as arq:
	for item in range(1600):
		filial = randint(1, 5000)
		ano = randint(1950, 2017)
		mes = randint(1, 12)
		cod_vendedor = randint(1, 50)
		temp0 = [ano, mes]
		ano_mes = "".join(map(str, temp0))
		temp = [filial, ano_mes, cod_vendedor]
		dados_venda.append(",".join(map(str, temp)))
		total_vendido.append(randint(0, 8000))

	dados_venda = list(set(dados_venda))

	if not ([k for k, v in Counter(dados_venda).items() if v > 1]) == 0 and len(dados_venda) >= 1500:
		for t in range(1500):
			arq.write(dados_venda[t] + "," + str(total_vendido[t]) + "\n")
	else:
		raise ValueError("Quantidade de dados insuficiente, nao foi possivel gerar o arquivo")
