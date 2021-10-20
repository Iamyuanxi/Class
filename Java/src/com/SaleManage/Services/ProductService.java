package com.SaleManage.Services;

import com.SaleManage.Entity.ProductInformation;
import com.SaleManage.Request;
import com.SaleManage.TableDTO;

public interface ProductService {
    TableDTO retrieveProducts(Request request);

    boolean add(ProductInformation productInformation);

    ProductInformation getByName(String selectedProductName);

    boolean update(ProductInformation productInformation);

    boolean delete(String[] name);
}
