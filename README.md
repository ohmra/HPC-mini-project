# HPC-mini-project
GRID5000

Sherical Harmonic Representation of Earth Elevation Data

# Execution sur grid5000
```
mpiexec -mca pml ^ucx --n 4 model --data /srv/storage/ppar@storage1.nancy.grid5000.fr/ETOPO1_small.csv --model m.txt --npoint 9 --lmax 2

./validate --data /srv/storage/ppar@storage1.nancy.grid5000.fr/ETOPO1_small.csv --model m.txt --lmax 2

mpiexec -mca pml ^ucx model --data /srv/storage/ppar@storage1.nancy.grid5000.fr/ETOPO1_small.csv --model m.txt --npoint 9 --lmax 2
```

# Execution en local
Pour executer en local, on aura besoin d'avoir MPI

```
mpiexec -mca pml ^ucx --n 4 model --data ./ETOPO1_small.csv --model m.txt --npoint 9 --lmax 2

./validate --data /srv/storage/ppar@storage1.nancy.grid5000.fr/ETOPO1_small.csv --model m.txt --lmax 2

mpiexec -mca pml ^ucx model --data ./ETOPO1_small.csv --model m.txt --npoint 9 --lmax 2
```

# Notes
Le fichier harmonics_old.c contient le code de base sans amélioration de la précision
Le fichier harmonics.c contient le code qui permet d'améliorer la précision mais rend l'execution du code
très lent (~4mn)

- Compilation:
	il est conseillé de renommer le fichier harmonics_old.c en harmonics.c si l'on veut juste
	mesurer le temps d'execution du code parallèle sans se soucier de la précision
	
	executer la commande make
		
- Execution:
	Les commandes d'executions de model et validate se trouvent dans le rapport
