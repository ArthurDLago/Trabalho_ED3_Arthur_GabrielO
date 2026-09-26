# 4. Processos × Threads — quadro de revisão

| Característica | Processo | Thread |
|---|---|---|
| Unidade de execução | Sim | Sim |
| Espaço de endereçamento | Normalmente próprio | Compartilhado com threads do processo |
| Pilha | Própria | Própria |
| Registradores/contexto | Próprio | Próprio |
| Código do processo | Próprio | Compartilhado |
| Heap | Normalmente próprio | Compartilhado |
| Isolamento | Maior | Menor |
| Comunicação | Pode exigir IPC | Memória compartilhada é natural |
| Sincronização | Necessária quando há recurso compartilhado | Frequentemente necessária |
| Criação | Em geral mais custosa | Em geral mais leve |

## Resumo para prova

### Processo
Pense em **isolamento + recursos + estado de execução**.

### Thread
Pense em **fluxo de execução + compartilhamento + contexto próprio**.

### Concorrência
Pense em **tarefas progredindo de forma intercalada ou simultânea**.

### Paralelismo
Pense em **execução simultânea em recursos de processamento distintos**.
