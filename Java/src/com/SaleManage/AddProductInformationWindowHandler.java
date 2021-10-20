package com.SaleManage;

import com.SaleManage.Entity.ProductInformation;
import com.SaleManage.Services.ProductService;
import com.SaleManage.Services.ProductServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddProductInformationWindowHandler implements ActionListener {
    private AddProductInformationWindow addProductInformationWindow;
    private ProductManageWindow productManageWindow;

    public AddProductInformationWindowHandler(AddProductInformationWindow addProductInformationWindow,ProductManageWindow productManageWindow) {
        this.addProductInformationWindow = addProductInformationWindow;
        this.productManageWindow = productManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("添加".equals(text)) {
            ProductService productService = new ProductServiceImpl();
            ProductInformation productInformation = addProductInformationWindow.buildProductInformation();

            boolean addResult = productService.add(productInformation);

            if (addResult) {
                productManageWindow.reloadTable();
                addProductInformationWindow.dispose();
            } else {
                JOptionPane.showMessageDialog(addProductInformationWindow,"添加失败");
            }
        }
    }
}
