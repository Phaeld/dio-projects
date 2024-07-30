from pymongo import MongoClient

# Substitua <username>, <password> e <cluster-url> com suas credenciais
client = MongoClient("mongodb+srv://phaelstdacnt:SEHDw0nKPK0AyyoU@database-mongo.ahzirr3.mongodb.net/")

# Criando o banco de dados
db = client['meu_banco']

# Definindo a coleção
colecao_bank = db['bank']

# Inserindo documentos de exemplo
documentos = [
    {
        'cliente_id': 1,
        'nome': 'João Silva',
        'email': 'joao@exemplo.com',
        'contas': [
            {
                'conta_id': 1,
                'numero': '12345',
                'saldo': 1000
            }
        ]
    },
    {
        'cliente_id': 2,
        'nome': 'Maria Souza',
        'email': 'maria@exemplo.com',
        'contas': [
            {
                'conta_id': 2,
                'numero': '67890',
                'saldo': 2000
            }
        ]
    }
]

# Inserindo os documentos na coleção
colecao_bank.insert_many(documentos)

# Recuperando todos os documentos
todos_documentos = colecao_bank.find()
for doc in todos_documentos:
    print(doc)

# Recuperando um cliente específico pelo nome
cliente_joao = colecao_bank.find_one({'nome': 'João Silva'})
print(cliente_joao)

# Recuperando contas de um cliente específico
cliente_maria = colecao_bank.find_one({'nome': 'Maria Souza'}, {'contas': 1, '_id': 0})
print(cliente_maria)
