package ro.ase.acs.container;

import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

public class IocContainer {
    private Map<Class<?>, Class<?>> map = new HashMap<>();

    public void register(Class<?> contract, Class<?> implementation) {
        map.put(contract, implementation);
    }

    public <T> T resolve(Class<?> contract) {
        try {
            return (T) map.get(contract).getDeclaredConstructor().newInstance();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
        return null;
    }

}
