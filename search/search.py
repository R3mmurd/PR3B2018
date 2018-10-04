import random


class Person:
    def __init__(self, **kwargs):
        # Constructor
        self.name        = kwargs['name']
        self.age         = kwargs['age']
        self.height      = kwargs['height']
        self.weight      = kwargs['weight']
        self.has_glasses = kwargs['has_glasses']

    def __str__(self):
        # Magic method to string representation
        s = '< name: "' + self.name + '", age: ' + str(self.age)\
            + ', height: ' + str(round(self.height, 2))\
            + ', weight: ' + str(round(self.weight, 2))\
            + ', has glasses: ' + str(self.has_glasses) + ' >'
        return s

    
def random_person(name):
    # Generates a person with a given name and random values.
    return Person(
        name=name,
        age=random.choice(range(18, 45)),
        height=random.uniform(1.5, 2.3),
        weight=random.uniform(60.0, 130.0),
        has_glasses=random.choice([
            True, True, True, False, False, False, False, False, False
        ]))
    

def search(s, c):
    for item in s:
        if c(item):
            return item

    return None

def variadic_search(s, c, *args):
    for item in s:
        if c(item, *args):
            return item

    return None


def first_height_greater_than_180(p):
    """
    Search criterium to a person with a height greater than 1.8 meters
    as a function.
    """
    return p.height > 1.8


class FirstHeightGreaterThan180:
    """
    Search criterium to a person with a height greater than 1.8 meters
    as a functor.
    """
    def __call__(self, p):
        # Magic method to make callable objects
        return p.height > 1.8

class FirstHeightGreaterThan:
    """
    Search criterium to a person with a height greater than h meters
    as a functor.
    """
    def __init__(self, h):
        self.h = h
        
    def __call__(self, p):
        # Magic method to make callable objects
        return p.height > self.h

    
def first_height_greater_than(p, h):
    """
    Search criterium to a person with a height greater than 1.8 meters
    as a function to be used by variadic_search.
    """
    return p.height > h

def first_height_greater_than_v2(p, *args):
    """
    Search criterium to a person with a height greater than 1.8 meters
    as a function to be used by variadic_search.
    """
    return p.height > args[0]


class FirstHeightGreaterThanV2:
    """
    Search criterium to a person with a height greater than h meters
    as a functor to be used by variadic_search.
    """
    def __call__(self, p, h):
        # Magic method to make callable objects
        return p.height > h


class FirstHeightGreaterThanV3:
    """
    Search criterium to a person with a height greater than h meters
    as a functor to be used by variadic_search.
    """
    def __call__(self, p, *args):
        # Magic method to make callable objects
        return p.height > args[0]
    
    
ps = [
    random_person('Steve'),
    random_person('Mike'),
    random_person('Paul'),
    random_person('John'),
    random_person('James'),
    random_person('Tarja'),
    random_person('Amy'),
    random_person('Floor'),
    random_person('Bruce'),
]

for p in ps:
    print(p)


r = search(ps, first_height_greater_than_180)

print('Result searching with a function')

if r:
    print('{} is the first person with height greater than 1.8'.format(r))
else:
    print('There is not person with height greater than 1.8')

r = search(ps, FirstHeightGreaterThan180())

print('Result searching with a functor')

if r:
    print('{} is the first person with height greater than 1.8'.format(r))
else:
    print('There is not person with height greater than 1.8')

r = search(ps, lambda p : p.height> 1.80)

print('Result searching with a lambda')

if r:
    print('{} is the first person with height greater than 1.8'.format(r))
else:
    print('There is not person with height greater than 1.8', r)

h = 1.5

r = search(ps, FirstHeightGreaterThan(h))

print('Result searching with a functor and h as variable')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))

r = search(ps, lambda p : p.height > h)

print('Result searching with a lambda and h as variable')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))


h = 1.6
    
r = variadic_search(ps, first_height_greater_than, h)
    
print('Result searching with a function and variadic_search')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))

r = variadic_search(ps, first_height_greater_than_v2, h)
    
print('Result searching with another function and variadic_search')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))

r = variadic_search(ps, FirstHeightGreaterThanV2(), h)

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))

r = variadic_search(ps, FirstHeightGreaterThanV3(), h)
    
print('Result searching with another functor and variadic_search')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))

r = variadic_search(ps, lambda p, h1 : p.height > h1, h)
    
print('Result searching with lambda and variadic_search')

if r:
    print('{} is the first person with height greater than {}'.format(r, h))
else:
    print('There is not person with height greater than {}'.format(h))
