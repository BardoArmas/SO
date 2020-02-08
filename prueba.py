ram=int(input("ingresa el valor de la ram"))
tb=int(input("ingresa el valor de los bloques de la ram"))
y=int(ram/tb)
print("el valor de Y es:",y)
if(ram % tb != 0):
    y= y + 1
print("el valor de Y es:",y)

datos={}
i=0
bloq=0
while i<=y:
    aux=bloq
    tar=input("ingrese nombre de la tarea")
    bloq= int(input("ingrese los bloques de la tarea"))
    bloq=i+bloq
    if(bloq<=y):
        for i in range(i,bloq):
            datos[i]=tar
        i=bloq    
        print("valor de i"+str(i))
    else :
        print("La tarea no se pudo agregar")
        i=bloq    
print(datos)
band1 = 1
j=0
print("y "+str(y))
while band1==1:
    tare = input("ingresa la tarea a eliminar")
    for j in range(j,y):
        print("j="+str(j)+" elemento:"+datos[j])
        if datos[j] == tare:
            print(tare)
            datos[j]=""
        else:
            print("else"+datos[j])
            
    j=0
    #i=bloq+1
    print(datos)
    band1 = 0
    
