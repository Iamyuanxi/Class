package com.SaleManage;

import com.SaleManage.Services.ProductService;
import com.SaleManage.Services.ProductServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ProductManageWindowHandler implements ActionListener {
    private ProductManageWindow productManageWindow;

    public ProductManageWindowHandler(ProductManageWindow productManageWindow) {
        this.productManageWindow = productManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("添加产品信息".equals(text)) {
            new AddProductInformationWindow(productManageWindow);
        } else if ("修改产品信息".equals(text)) {
            String[] selectedProductNames = productManageWindow.getSelectedProductNames();

            if (selectedProductNames.length != 1) {
                JOptionPane.showMessageDialog(productManageWindow, "一次只能修改一行！");
                return;
            }

            new UpdateProductWindow(productManageWindow, selectedProductNames[0]);
        } else if("删除产品信息".equals(text)) {
            String[] selectedProductNames = productManageWindow.getSelectedProductNames();

            if (selectedProductNames.length == 0) {
                JOptionPane.showMessageDialog(productManageWindow,"请选择要删除的行！");
                return;
            }

            int option = JOptionPane.showConfirmDialog(productManageWindow,"确定要删除选择的"+selectedProductNames.length+"行吗？","确认删除",JOptionPane.YES_NO_OPTION);

            if (option == JOptionPane.YES_OPTION) {
                ProductService productService = new ProductServiceImpl();
                boolean deleteResult = productService.delete(selectedProductNames);

                if (deleteResult) {
                    productManageWindow.reloadTable();
                } else {
                    JOptionPane.showMessageDialog(productManageWindow,"删除失败");
                }
            }
        } else if ("查询".equals(text)) {
            productManageWindow.reloadTable();
        } else if ("添加销售信息".equals(text)) {
            new AddMarketInformationWindow(productManageWindow);
        }
    }
}
