from sqlalchemy import create_engine
from sqlalchemy import Column
from sqlalchemy import Integer
from sqlalchemy import String
from sqlalchemy import ForeignKey
from sqlalchemy import Numeric
from sqlalchemy import BINARY
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship, sessionmaker

# Definindo a base
Base = declarative_base()

# Definindo as classes/tabelas
class Cliente(Base):
    __tablename__ = 'clientes'
    id = Column(Integer, primary_key=True)
    nome = Column(String, nullable=False)
    cpf = Column(String(9), nullable=False)
    endereco = Column(String, nullable=False)

    contas = relationship('Conta', back_populates='cliente')

class Conta(Base):
    __tablename__ = 'contas'
    id = Column(BINARY, primary_key=True)
    tipo = Column(String, nullable=False)
    agencia = Column(String, nullable=False)
    num = Column(Integer, nullable=False)
    id_cliente = Column(Integer, ForeignKey('clientes.id'), nullable=False)
    saldo = Column(Numeric, nullable=False)

    cliente = relationship('Cliente', back_populates='contas')

# Conectando ao SQLite
engine = create_engine('sqlite:///meu_banco.db')
Base.metadata.create_all(engine)

# Criando uma sessão
Session = sessionmaker(bind=engine)
session = Session()

# Inserindo dados de exemplo
cliente1 = Cliente(nome='João Silva', cpf='123456789', endereco='Rua A, 123')
conta1 = Conta(id=b'1', tipo='corrente', agencia='0001', num=12345, id_cliente=1, saldo=1000.50, cliente=cliente1)

cliente2 = Cliente(nome='Maria Souza', cpf='987654321', endereco='Avenida B, 456')
conta2 = Conta(id=b'2', tipo='poupança', agencia='0002', num=67890, id_cliente=2, saldo=2000.75, cliente=cliente2)

session.add_all([cliente1, conta1, cliente2, conta2])
session.commit()

# Recuperando todos os clientes
clientes = session.query(Cliente).all()
for cliente in clientes:
    print(f'Cliente: {cliente.nome}, CPF: {cliente.cpf}, Endereço: {cliente.endereco}')

# Recuperando todas as contas de um cliente específico
cliente = session.query(Cliente).filter_by(nome='João Silva').first()
for conta in cliente.contas:
    print(f'Conta Tipo: {conta.tipo}, Agência: {conta.agencia}, Número: {conta.num}, Saldo: {conta.saldo}')
