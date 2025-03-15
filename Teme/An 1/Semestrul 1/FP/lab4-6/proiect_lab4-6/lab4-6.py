import math
lista = []
def print_meniu():
    '''
    Functia tipareste optiunile din meniul aplicatiei
    :return: None
    '''
    print(' 0.Afisarea listei curente\n 1.Adaugarea unui numar in lista\n 2.Tiparirea partii imaginare a numerelor dintr-o secventa\n 3.Tiparirea numerelor cu modululul mai mic decat 10\n 4.Tiparirea numerelor cu modulul egal cu 10\n 5.Tiparirea sumei numerelor dintr-o secventa\n 6.Tiparirea produsului numerelor dintr-o secventa\n 7.Tiparirea numerelor din lista sortate descrescator dupa partea imaginara\n 8.Iesire')

def verify_insert_number():
    x = input("Introduceti partea reala:")
    y = input("Introduceti parea imaginara:")
    poz = input("Introduceti pozitia:")
    try:
        insert_number(lista, float(x), float(y), int(poz))
    except ValueError:
        print("Introduceti x, y reale si poz intreg")


def verify_sequence(f):
    start = input("Introduceti inceputul secventei:")
    end = input("Introduceti sfarsitul secventei:")
    try:
        f(lista, int(start), int(end)+1)
    except ValueError:
        print("Introduceti start si end intregi")


def print_lista_ui(sir_nr):
    '''
    Functia construieste si tipareste lista pe care o va vedea utilizatorul
    :param sir: list
    :return: None
    '''
    lista_ui = []
    #lista pe care o va vedea utilizatorul
    for i in range(len(sir_nr)):
        if sir_nr[i][1] >= 0:
            nr = str(sir_nr[i][0]) + '+' + str(sir_nr[i][1]) + 'i'
        else:
            nr = str(sir_nr[i][0]) + str(sir_nr[i][1]) + 'i'
        lista_ui.append(nr)
    print(lista_ui)

def insert_number(sir_nr, re, im, poz):
    '''
    Functia adauga elementul [x, y] pe pozitia poz sau la final pentru poz = -1
    :param list: list
    :param x: float
    :param y: float
    :param poz: int
    :return: list
    '''
    if poz == -1:
        sir_nr.append([re, im])
    else:
        sir_nr.insert(poz, [re, im])
    return sir_nr


def imaginary_part(sir_nr, poz):
    '''
    Functia returneaza partea imaginara a numarului din lista al carui index este poz
    :param list: list
    :param paz: int > 0
    :return: float
    '''
    return sir_nr[poz][1]



def imaginary_part_sequence(sir_nr, start, end):
    '''
    Functia returneaza lista formata din partile imaginare ale numerelor ale caror indecsi se afla in intervalul [start, end]
    :param sir_nr: list
    :param start: int > 0
    :param end: int > 0
    :return: list
    '''
    imaginary_parts = []
    for i in range(start, end+1):
        imaginary_parts.append(imaginary_part(sir_nr, i))
    return imaginary_parts

def modulus(nr_complex):
    '''
    Functia returneaza modulul unui numar complex
    :param nr_complex: list
    :return: float
    '''
    return math.sqrt(nr_complex[0]**2 + nr_complex[1]**2)



def modulus_less_than(sir_nr, max):
    '''
    Functia returneaza lista formata din nr complexe |z| < max
    :param sir: sir_nr
    :param max: float > 0
    :return: sir_gasit: list
    '''
    sir_gasit = []
    for nr in sir_nr:
        if modulus(nr) < max:
            sir_gasit.append(nr)
    if len(sir_gasit) == 0:
        return 'Nu exista numere care respcecta aceasta conditie'
    return sir_gasit



def modulus_equal_with(sir_nr, value):
    '''
    Functia returneaza lista formata din nr complexe |z| = value
    :param sir_nr: list
    :param max: float > 0
    :return: sir_gasit: list
    '''
    sir_gasit = []
    for nr in sir_nr:
        if modulus(nr) == value:
            sir_gasit.append(nr)
    return sir_gasit

def sum_sequence(sir_nr, start, end):
    '''
    Functia returneaza suma numerelor din secventa determinata de [start, end]
    :param sir_nr: list
    :param start: int > 0
    :param end: int > 0
    :return: lista_sum: list
    '''
    lista_sum = []
    #vom stoca rezultatul sumei intr o lista pentru a putea fi afisat utilizatorului prin functia print_lista_ui
    suma = []
    #vom stoca rezultatul sumei sub forma unei liste cu 2 elemente (partea reala si partea imaginara)
    re = 0
    im = 0
    for i in range(start, end+1):
        re += sir_nr[i][0]
        im += sir_nr[i][1]
    suma.append(re)
    suma.append(im)
    lista_sum.append(suma)
    return lista_sum

def product(nr_1, nr_2):
    '''
    Functia returneaza produsul a doua numere complexe
    :param nr_1: list [re1, im1]
    :param nr_2: list [re2, im2]
    :return: p: list [re, im]
    '''
    p = []
    re = nr_1[0]*nr_2[0] - nr_1[1]*nr_2[1]
    im = nr_1[0]*nr_2[1] + nr_1[1]*nr_2[0]
    p.append(re)
    p.append(im)
    return p

def product_sequence(sir_nr, start, end):
    '''
    Functia returneaza produsul numerelor din secventa determinata de [start, end]
    :param sir_nr: list
    :param start: int > 0
    :param end: int > 0
    :return: p_sequence: list
    '''
    p_sequence = [[1, 0]]
    for i in range(start, end+1):
        p_sequence = [product(p_sequence[0], sir_nr[i])]
    return p_sequence

def order_by_imaginary(sir_nr):
    '''
    Functia returneaza o copie a listei de numere complexe (are aceleasi elemente), dar ordonate descrescator dupa partea imaginara
    :param sir_nr: list
    :return: list
    '''
    sir_nr_1 = sir_nr.copy()
    sortat = False
    while sortat == False:
        sortat = True
        for i in range(len(sir_nr_1)-1):
            if sir_nr_1[i][1] < sir_nr_1[i+1][1]:
                sortat = False
                sir_nr_1[i], sir_nr_1[i+1] = sir_nr_1[i+1], sir_nr_1[i]
    return sir_nr_1

def delete_number(sir_nr, i):
    '''
    Functia returneaza lista dupa eliminarea numarului de pe pozitia i
    :param sir_nr: list
    :param i: int
    :return: list
    '''
    sir_nr.pop(i)
def test_insert_number():
    sir = []
    assert(insert_number(sir, 2, 3, -1)) == [[2, 3]]
    assert(insert_number(sir, 3, -2, -1)) == [[2, 3], [3, -2]]
    assert(insert_number(sir, 4, 5, 1)) == [[2,3], [4, 5], [3, -2]]
    assert(insert_number(sir, 1, 0, 0)) == [[1, 0], [2, 3], [4, 5], [3, -2]]

def test_imaginary_part():
    sir = [[2, -4], [3, 5]]
    assert(imaginary_part(sir, 0) == -4)
    assert (imaginary_part(sir, 1) == 5)

def test_imaginary_part_sequence():
    sir = [[2, 4], [3, 4], [2, 0]]
    assert(imaginary_part_sequence(sir, 0, 1) == [4, 4])
    assert(imaginary_part_sequence(sir, 1, 2) == [4, 0])

def test_modulus():
    lista_nr = [[2, 4], [3, 4], [2, 0]]
    assert(modulus(lista_nr[0]) == 4.47213595499958)
    assert(modulus(lista_nr[1]) == 5)
    assert(modulus(lista_nr[2]) == 2)

def test_sum_sequence():
    lista_sum = [[4, 10], [10, -2], [2, 4]]
    assert(sum_sequence(lista_sum, 0, 1) == [[14, 8]])
    assert(sum_sequence(lista_sum, 0, 2) == [[16, 12]])

def test_product():
    lista_nr_1 = [[2, 4], [1, 3]]
    lista_nr_2 = [[1, 5], [-2.5, 0]]
    assert(product(lista_nr_1[0], lista_nr_2[0]) == [-18, 14])
    assert(product(lista_nr_1[1], lista_nr_2[1]) == [-2.5, -7.5])

def test_order_by_imaginary():
    siruri_nr = [[[1, 4], [2, 0], [-3, -2.5], [4, 0.7]], [[10, -11], [14, 20], [-25, 30]]]
    assert(order_by_imaginary(siruri_nr[0])) == [[1, 4], [4, 0.7], [2, 0], [-3, -2.5]]
    assert(order_by_imaginary(siruri_nr[1])) == [[-25, 30], [14, 20], [10, -11]]

def test_delete_number():
    sir_nr = []
    insert_number(sir_nr, 2, 4, 0)
    insert_number(sir_nr, 4, 5, 1)
    insert_number(sir_nr, -2, -4.5, 2)
    assert(delete_number(sir_nr, 1) == [[2, 4], [-2, -4.5]])
    assert(delete_number(sir_nr, 0) == [[-2, -4.5]])

def run():
    while True:
        print_meniu()
        option = int(input("Introduceti o optiune:"))
        match option:
            case 0:
                print_lista_ui(lista)
            case 1:
                verify_insert_number()
                print_lista_ui(lista)
            case 2:
                start = int(input("Introduceti inceputul secventei:"))
                end = int(input("Introduceti sfarsitul secventei:"))
                print(imaginary_part_sequence(lista, start, end))
            case 3:
                print_lista_ui(modulus_less_than(lista, 10))
            case 4:
                print_lista_ui(modulus_equal_with(lista, 10))
            case 5:
                start = int(input("Introduceti inceputul secventei:"))
                end = int(input("Introduceti sfarsitul secventei:"))
                print_lista_ui(sum_sequence(lista, start, end))
            case 6:
                start = int(input("Introduceti inceputul secventei:"))
                end = int(input("Introduceti sfarsitul secventei:"))
                print_lista_ui(product_sequence(lista, start, end))
            case 7:
                print_lista_ui(order_by_imaginary(lista))
            case 8:
                break
test_insert_number()
test_imaginary_part_sequence()
test_modulus()
test_sum_sequence()
test_product()
test_order_by_imaginary()
# test_delete_number()
run()