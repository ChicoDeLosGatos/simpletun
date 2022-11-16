# Comandos de git

Clonar proyecto:
```
git clone git@github.com:ChicoDeLosGatos/simpletun
```

Hacer pull o actualizar proyecto:
```
git pull nombre_de_remoto nombre_de_rama //generalmente el nombre de remoto es origin y la rama principal es master
//git pull origin master haria un pull del remoto origin en su rama principal, master
```

Añadir cambios al buffer de git de tu repositorio `LOCAL`
```
git add .
git commit -m "Qué has cambiado?"
```

Actualizar los camnbios del buffer de tu repositorio `LOCAL` en el repositorio `COMPARTIDO`
```
git push nombre_de_remoto nombre_de_rama //funciona del mismo modo que el comando pull
```

Crear una nueva rama o cambiar de rama:
```
git checkout -b nombre_de_rama
```
