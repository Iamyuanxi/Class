package com.SaleManage.Services;

import com.SaleManage.Entity.Salesman;
import com.SaleManage.Request;
import com.SaleManage.TableDTO;

public interface SalesmanService {
    TableDTO retrieveSalesmans(Request request);

    boolean add(Salesman salesman);

    Salesman getByNumber(String selectedSalesmanNumber);

    boolean update(Salesman salesman);

    boolean delete(String[] numbers);
}
