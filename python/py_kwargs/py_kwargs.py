class SupperClass():
    def __init__(self, a=None, b=None, **kwargs):
        print(a,b,kwargs)
        super().__init__(**kwargs)
        
class subClass(SupperClass):
    def __init__(self,a=None,b=None, **kwargs):
        # kwargs['a']=a
        # kwargs['b']=b
        print('kwargs hold %s'%kwargs)
        print('A and B now holds %s %s'%(a, b))
        super().__init__(**kwargs)

class TwinClass():
    def __init__(self, **kwargs):
        print(kwargs)
        # super().__init__(**kwargs)
        # print(c,d)

class aClass(subClass, TwinClass):#, subClass):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

sc = aClass(a=1,b=2, c='3',d='4')

class somethingElse:
    def __init__(self,a=None, b=None):
        print(a,b)

sc = somethingElse(1,2)