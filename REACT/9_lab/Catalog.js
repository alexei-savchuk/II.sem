// Catalog.js
import React, { useState } from "react";
import SortTable, { getSortedProducts } from "./SortTable";

const Catalog = () => {
  const [sortedBy, setSortedBy] = useState("isNew");
  const [sortDirection, setSortDirection] = useState("desc");

  const handleSort = (columnName) => {
    if (columnName === sortedBy) {
      setSortDirection(sortDirection === "asc" ? "desc" : "asc");
    } else {
      setSortedBy(columnName);
      setSortDirection("asc");
    }
  };

  const renderProducts = () => {
    const sortedProducts = getSortedProducts(sortedBy, sortDirection);
    return sortedProducts.map((product) => {
      let stockColor = "";
      if (product.stock === 0) {
        stockColor = "red";
      } else if (product.stock < 3) {
        stockColor = "yellow";
      }
      const discountedPrice = product.price * (1 - product.discount / 100);

      return (
        <div key={product.id} className="product">
          <div className="product-image">
            <img src={product.image} alt={product.name} className="product-thumbnail" />
          </div>
          <div className="product-details">
            <h3 className="product-name">{product.name}</h3>
            <p className="product-description">{product.description}</p>
            {product.isNew && <span className="product-tag new">New</span>}
            <div className="product-price">
              {product.discount > 0 && (
                <span className="product-discounted-price">${discountedPrice.toFixed(2)}</span>
              )}
              <span className="product-original-price">${product.price.toFixed(2)}</span>
            </div>
            <div className="product-stock" style={{ backgroundColor: stockColor }}>
              {product.stock > 0 ? "In Stock" : "Out of Stock"}
            </div>
          </div>
        </div>
      );
    });
  };

  return (
    <div className="catalog">
      <h2 className="catalog-heading">Catalog</h2>
      <div className="catalog-sort">
        <span className="sort-label">Sort by:</span>
        <button className="sort-button" onClick={() => handleSort("name")}>
          Name
        </button>
        <button className="sort-button" onClick={() => handleSort("price")}>
          Price
        </button>
        <button className="sort-button" onClick={() => handleSort("stock")}>
          Stock
        </button>
        <button className="sort-button" onClick={() => handleSort("isNew")}>
          New
        </button>
      </div>
      <div className="catalog-products">{renderProducts()}</div>
    </div>
  );
};

export default Catalog;
